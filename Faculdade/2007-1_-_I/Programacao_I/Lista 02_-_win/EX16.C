                        /*Marco Tulio*/

#include <math.h>
#include <stdio.h>
main () {
     int n, raiz, comparacao;
     printf ("\n\t\t\tExercicio 16 - Lista 02\n\n");
     printf ("Digite um numero inteiro: ");
     scanf ("%i", &n);
     
     raiz = sqrt(n);
     comparacao = raiz*raiz;
     
     if (n == comparacao) {
           printf ("\nO inteiro %i e´ quadrado perfeito de %i",raiz, n);
           
     }
     else printf ("\nO Inteiro %i não e´ um quadrado perfeito",n);
     
     getchar();
     
     fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux
     getchar();
}

