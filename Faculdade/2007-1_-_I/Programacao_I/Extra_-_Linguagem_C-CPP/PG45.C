/*Pg45...OPeradores relacionais e Logicos.
O programa contem a fun��o xor(), que devolve o resultado de uma opera��o OR(|| ou) 
exclusivo realizada nos dois argumentos*/

#include<stdio.h>
int xor (int a, int b);
int main (void) {
     printf ("%d", xor (1, 0));
     printf ("%d", xor (1, 1));
     printf ("%d", xor (0, 1));
     printf ("%d", xor (0, 0));
     getchar();
     getchar();
     }
     xor (int a, int b)
    
     
     {
         return (a || b) && !(a &&b);

     }
