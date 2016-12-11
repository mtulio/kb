#include <stdio.h>
main () {
     float R,H,V,A;
     printf ("\n**CALCULO DO VOLUME E A AREA DO CILINDRO**\n\n");
     printf ("Qual o raio do cilindro? ");
     scanf ("%f",&R);
     printf ("Qual a altura do cilindro? ");
     scanf ("%f",&H);
     V = 3.1415 * R * R * H;
     A = 2 * 3.1415 * R * (R + H);
     printf ("\nO volume do cilindro e: %f.\n",V);
     printf ("\nA area do cilindro e: %f.\n", A);
     printf ("\n\n<< Marco Tulio >>\n");
     getchar(),getchar();
}
