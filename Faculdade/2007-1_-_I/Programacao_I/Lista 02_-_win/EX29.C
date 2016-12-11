                        /*Marco Tulio*/

#include <string.h>
#include <stdio.h>
int main (void) {
    printf ("\n\t\t\tExercicio 29 - Lista 02\n\n");
    char nome[30];
    float hrextra, salbruto, saliquido;
    printf ("Informe o nome do fnucionario: ");
    gets(nome);
    printf ("Informe as horas extras trabalhadas: ");
    scanf ("%f", &hrextra);
    
    /*Constantes: Salario: 350.00, Hora extra: 10.00*/
    
    salbruto = 3.0*350.0 + (hrextra*10.0);
    if (salbruto<=1500.0){
       printf ("\nNome: %s\nSalario Bruto: R$%.2f\nSalario Liquido: R$%.2f\n\n",nome, salbruto, salbruto);
    }
    if ( (salbruto > 1500.0) && (salbruto <= 2000.0)){
       saliquido = salbruto - 0.12*salbruto;
       printf ("\nNome: %s\nSalario Bruto: R$%.2f\nSalario Liquido: R$%.2f\n\n",nome, salbruto, saliquido);
    }
    if ((salbruto > 2000.0)){
       saliquido = salbruto - 0.32*salbruto;
       printf ("\nNome: %s\nSalario Bruto: R$%.2f\nSalario Liquido: R$%.2f\n\n",nome, salbruto, saliquido);
    }
    getchar();
    getchar();
}    
