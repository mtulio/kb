#include <stdio.h>
main () {
     int M,N,L1,L2,H;
     printf ("\n ** CALCULO DOS LADOS E DA HIPOTENUSA ** \n");
     printf ("\nDigite o valor de M: ");
     scanf ("%i",&M);
     printf ("Digite o valor de N (M>N): ");
     scanf ("%i",&N);
     L1 = M * M - N * N;
     L2 = 2 * M * N;
     H = M * M + N * N;
     printf ("\nO valor do lado 1 e: %i.\n",L1);
     printf ("O valor do lado 2 e: %i.\n",L2);
     printf ("O valor da hipotenusa e: %i.\n",H);
     printf ("\n\n<< Marco_Tulio >>\n");
     getchar(),getchar();
}
