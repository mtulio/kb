#include <stdio.h>
main () {
     int t1,horas,r1,min,seg;
     printf ("\nDigite o tempo em segundos: ");
     scanf ("%i",&t1);
     horas = t1 / 3600;
     r1 = t1 % 3600;
     min = r1 / 60;
     seg = r1 % 60;
     printf ("\nO tempo informado e: %i (Horas): %i (Minutos): %i (Segundos).\n",horas,min,seg);
     printf ("\n\n<< Marco Tulio >>\n");
     getchar(),getchar();
}
      
