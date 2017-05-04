                     /*Marco Tulio*/

#include <stdio.h>
#include <string.h>
main () {
     char opt[3];
     float pinicial, acessorio, pfinal;
     printf ("\n\t\t\tExercicio 36 - Lista 02\n\n");
     printf ("Digite o preço inicial do carro: ");
     scanf ("%f", &pinicial);
     
     //para diminuir os calculos:
     printf ("(a)-Ar Condicionado: R$ 1.750,00\n(b)-Pintura Metalica: R$ 800,00\n(c)-Vidro Eletrico: R$ 1.200,00\n(d)-Direção Hidraulica: R$ 2.000,00\nInforme o(s) valor(es) do(s) acessorio(s) desejado(s): ");
     scanf ("%f", &acessorio);
     
     //printf ("(a)-Ar Condicionado: R$ 1.750,00\n(b)-Pintura Metalica: R$ 800,00\n(c)-Vidro Eletrico: R$ 1.200,00\n(d)-Direção Hidraulica: R$ 2.000,00\nInforme o codigo do acessorio desejado: ");
     //scanf ("%f", &acessorio1);
     
     //printf ("Deseja adicionar mais acessorios? y ou n: ");
     //if ( strcmp(addace, 'y'){
       //   printf ("(a)-Ar Condicionado: R$ 1.750,00\n(b)-Pintura Metalica: R$ 800,00\n(c)-Vidro Eletrico: R$ 1.200,00\n(d)-Direção Hidraulica: R$ 2.000,00\nInforme o codigo do acessorio desejado: ");
         // scanf ("%f", &acessorio2);
     //else if ( strcmp(addace, 'n') )
     
     pfinal = pinicial + acessorio;
     printf ("\nPreço final do carro: R$ %.f\n\n",pfinal);
     
     fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux
     getchar();
     
}
