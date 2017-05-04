#include <stdio.h>
main () {
     float H,R,A,V;
     printf ("\n ** CALCULO DO VALOR DE UMA LATA ** \n");
     printf ("\nDigite a altura: ");
     scanf ("%f",&H);
     printf ("Digite o raio: ");
     scanf ("%f",&R);
     A = 2.0 * 3.1415 * R * R + 2.0 * 3.1415 * R * H;
     V = A * 100.0;
     V = V/10000;
     printf ("\nO valor da lata e: %f reais.\n",V);
     printf ("\n\n<< Marco_Tulio >>\n");
     getchar(),getchar();
}
