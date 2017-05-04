
                     /*Marco Tulio*/
#include <stdio.h>
#include <string.h>
main () {
     char opt[3];
     float qtdlt, vlpg;
     printf ("\n\t\t\tExercicio 35 - Lista 02\n\n");
     printf ("\t(A)-Alcool\n\t(D)-Diesel\n\t(G)-Gasolina\nInforme o Combustivel: ");
     scanf ("%s", &opt);
     printf ("Digite a quantidade de Litros: ");
     scanf ("%f", &qtdlt);
     if ( strcmp(opt,"A") && strcmp(opt,"a") ) {
          vlpg = qtdlt*1.805;
     }
     if ( strcmp(opt,"D") || strcmp(opt,"d") ) {
          vlpg = qtdlt*1.053;
     }
     if ( strcmp(opt,"G") || strcmp(opt,"g")  ) {
          vlpg = qtdlt*1.805;
     }
     printf ("\nQuantidade de Litros: %.2f\nTotal a Pagar: R$%.2f\n",qtdlt, vlpg);
     
      fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux
     getchar();
}
