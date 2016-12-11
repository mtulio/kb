/*Pg45...OPeradores relacionais e Logicos.
O programa contem a função xor(), que devolve o resultado de uma operação OR(|| ou) 
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
