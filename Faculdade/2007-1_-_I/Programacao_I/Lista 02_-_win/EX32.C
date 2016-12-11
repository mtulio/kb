                    /*Marco Tulio*/
/*VERIFICAR*/
/*O meu msdos da pau na hora de imprimir os resultados.Obs: Sem erros de compilação*/

#include <stdio.h>
#include <string.h>
int main (void) {
     printf ("\n\t\t\tExercicio 32 - Lista 02\n\n");
     char nome[15], sobrenome[20], tpcc[10];
     int conta;
     float saldosemest, saldomes, tarifa;
     printf ("Digite o nome do cliente: ");
     gets (nome);
     printf ("Digite o sobrenome: ");
     gets (sobrenome);
     strcat (nome," ");
     strcat (nome,sobrenome);
     printf ("Digite o numero da Conta: ");
     scanf ("%i", &conta);
     printf ("Digite o Saldo Bancario Semestral total: ");
     scanf ("%f", saldosemest);
     saldomes = saldosemest/6.0;
     if (saldomes <= 1000.0) {
        tarifa = 25.00;
        strcat(tpcc,"Basica");
     }
     if ( (saldomes >= 1000.01) && (saldomes <= 2000.0) ) {
        tarifa = 20.0;
        strcat(tpcc,"Prata");
     }
     if ( (saldomes >= 2000.01) && (saldomes <= 3500.0) ) {
        tarifa = 13.0;
        strcat(tpcc,"Ouro");
     }
     if ( saldomes > 3500.0 ) {
        strcat(tpcc,"Prêmio");
        printf ("\nNome: %s \nConta: %.0i \nMedia Saldo Mensal: R$%.2f \nTipo de Conta: %s \nTarifa Bancaria: Isento\n\n", nome, conta, saldomes, tpcc);
     }     
     printf ("\nNome: %s\nConta: %.0i\nMedia Saldo Mensal: R$%.2f\nTipo de Conta: %s\nTarifa Bancaria: R$%.0f \n\n",nome, conta, saldomes, tpcc, tarifa);
     
     getchar();
     getchar();

}
