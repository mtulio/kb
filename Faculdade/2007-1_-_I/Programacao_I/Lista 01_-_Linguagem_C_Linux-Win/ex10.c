#include <stdio.h>
main () {
     int b,h,v;
     printf ("\n** CALCULAR VOLUME DA PIRAMIDE ** \n");
     printf ("\nQual a base da piramide? ");
     scanf ("%i",&b);
     printf ("Qual a altura da piramide? ");
     scanf ("%i",&h);
     v = (b * h)*1/3 ;
     printf ("\nO Volume da piramide e: %i.\n",v);
     printf ("\n\n<< Marco_Tulio >>\n");
     getchar(),getchar();
}
