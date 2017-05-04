#include <stdio.h>
main () {
     int tp,v1,v2;
     float lc;
     printf ("\n**LOCADORA DE CHARRETES - CALCULO DE ALUGUEL**\n");
     printf ("\nQual o tempo em horas? ");
     scanf ("%i",&tp);
     v1 = tp / 3;
     v2 = tp % 3;
     lc = v1 * 8.50 + v2 * 3.50;
     printf ("\nO valor a pagar e: R$ %f .\n",lc);
     printf ("\n<< Marco_Tulio >>\n");
     getchar(),getchar();    
}     
