#include <stdio.h>
main () {
     float F,C;
     printf ("\n ** CONVERSOR DE TEMPERATURA FAHRENHEIT EM CELSIUS **\n" );
     printf ("\nDigite a temperatura em Fahrenheit: ");
     scanf ("%f",&F);
     C = 5.0 / 9.0 * (F - 32.0);
     printf ("\nA temperatura em Celsius e: %i.\n",C);
     printf ("\n\n<< Marco_Tulio >>");
     getchar(),getchar();
}
