                    /*Marco Tulio*/

#include <stdio.h>
main () {
     printf ("\n\t\t\tExercicio 13 - Lista 02\n\n");
     int n, carac1, carac11, carac12;
     float carac2;
     printf ("\nDigite um numero com 4 digitos: ");
     scanf ("%i", &n);
     carac11 = ((n/1000)*10 + ((n%1000)/100));
     carac12 = (((n%1000)%100)/10)*10 + (((n%1000)%100)%10);
     carac1 = carac11 + carac12;
     carac2 = sqrt(n);
     if ( carac1==carac2 ) {
          printf ("\n\nO Numero %i tem as seguintes caracteristicas:\n%.0i + %.0i = %.0i\n%.0i^2 = %.0i\n\n",n, carac11, carac12, carac1, carac1, n);
     }
     else printf ("\n\nO Numero %.0i não tem as caracteristicas exigidas!\n\n",n);
     getchar();
     getchar();
} 
