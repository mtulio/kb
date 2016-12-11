#include <stdio.h>
main () {
     int n, raiz, comparacao;
     printf ("Digite um numero inteiro: ");
     scanf ("%i", &n);
     
     raiz = sqrt(n);
     comparacao = raiz*raiz;
     
     if (n == comparacao) {
           printf ("\nO inteiro %i e´ quadrado perfeito de %i",raiz, n);
           
     }
     else printf ("\nO Inteiro %i não e´ um quadrado perfeito",n);
     
     getchar();
     getchar();
}
