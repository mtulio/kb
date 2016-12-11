                        /*Marco Tulio*/

#include <stdio.h>
main () {
     printf ("\n\t\t\tExercicio 25 - Lista 02\n\n");
     char nomeposto[20];
     float consanual, consmes, newpreco;
     printf ("\n\t\tDistribuidora de combustiveis Ave Maria\n\n");
     printf ("Digite o nome do Posto: ");
     gets(nomeposto);
     printf ("Informe o consumo anual, em litros: ");
     scanf ("%f", &consanual);
     consmes = consanual/12.0;
     if ( consmes <=50000.0 ){
          newpreco = 2.13*1.20;
     }
     if ( consmes >50000 ) {
          newpreco = 2.13*1.12;
     }
     printf ("\nO novo preço de combustivel para o Posto %s é de R$ %.2f p/litro.\n\n",nomeposto, newpreco);
     getchar();
     getchar();
}
