#include<stdio.h>
main () {
     int anos=1;
     float crescimentoA=90000000.0, crescimentoB=200000000.0;
     
     
     printf ("\nCalculo da taxa de crescimento da popula��o de 2 Paises: A e B.\n\tPais A inicialmente com 90.000.000 Habitantes\n\tPais B inicialmente com 200.000.000 Habitantes\n\nTecle ENTER para iniciar...Aguardando!");
     getchar();
     for ( ;crescimentoB > crescimentoA; ) {
         crescimentoA = 1.03*crescimentoA;
         crescimentoB = 1.015*crescimentoB;
         anos++;
     }
     //printf ("\nPopula�ao do Pais A: %.0f milhoes de Habitantes\nPopula�ao do Pais B: %.0f milhoes de Habitantes",crescimentoA, crescimentoB);
     
     if (crescimentoA==crescimentoB) printf ("\n\nA Popula�ao do Pais A se igualou a Popula�ao do Pais B em %i anos.", anos);
     if (crescimentoA>crescimentoB) printf ("\n\nA Popula�ao do Pais A Ultrapassou a Popula�ao do Pais B em %i anos.", anos);
     getchar();
     getchar();
}
