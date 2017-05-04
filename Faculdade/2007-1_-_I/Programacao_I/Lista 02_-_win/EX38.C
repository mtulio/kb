                     /*Marco Tulio*/

#include<stdio.h>
main () {
     int x, y;
     printf ("\n\t\t\tExercicio 33 - Lista 02\n\n");
     printf ("Digite o valor de x: ");
     scanf ("%i", &x);
     printf ("Digite o valor de y: ");
     scanf ("%i", &y);
     
     if (x==0 & y==0) { printf ("\nO Ponto (0,0) está no Ponto Central!");}
     
     if (x>=1 & y>=1) { printf ("\nO Ponto (%.0i,%.0i) estão no 1 Quadrante!\n",x, y); }
     if (x<0 & y<0) { printf ("\nO Ponto (%.0i,%.0i) estão no 3 Quadrante!\n",x, y); }
     
     if (x<0 & y>=1) { printf ("\nO Ponto (%.0i,%.0i) estão no 2 Quadrante!\n",x, y); }
     if (x>=1 & y<0) { printf ("\nO Ponto (%.0i,%.0i) estão no 4 Quadrante!\n",x, y); }
     
     if (x==0) {
               if (y>=1) { printf ("\nCoordenada x sobre o eixo das Abscissas e y no 1 ou 2 Quadrante!\n"); }
               if (y<0) { printf ("\nCoordenada x sobre o eixo das Abscissas e y no 3 ou 4 Quadrante!\n"); }
     }
     
     if (y==0) {
               if (x>1) { printf ("\nCoordenada x no 1 ou 4 Quadrante e y no eixo das Ordenadas!\n"); }
               if (x<0) { printf ("\nCoordenada x no 2 ou 3 Quadrante e y no eixo das Ordenadas!\n"); }
     }
     
     
     getchar();
     getchar();
     
}
