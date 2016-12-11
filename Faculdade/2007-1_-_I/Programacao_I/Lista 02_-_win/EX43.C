                     /*Marco Tulio*/
                     
#include <string.h>
#include <stdio.h>
main () {
     char nome[15];
     float peso, altura, imc;
     printf ("\n\t\t\tExercicio 33 - Lista 02\n\n");
     printf ("\t\tCalculo do Indice de Massa Corporal (IMC)\n");
     printf ("Digite o nome do paciente: ");
     scanf ("%s", &nome);
     printf ("Digite o peso do paciente: ");
     scanf ("%f", &peso);
     printf ("Digite a altura do paciente: ");
     scanf ("%f", &altura);
     imc = ( peso/(pow(altura,2)) );
     
     if (imc<=20.0) { printf ("\nNome do paciente: %s\nFaixa de Risco: abaixo do peso ideal.\n",nome); }
     
     if (imc>20.0 & imc<=25.0) { printf ("\nNome do paciente: %s\nFaixa de Risco: peso normal.\n",nome); }
     
     if (imc>25.0 & imc<=30.0) { printf ("\nNome do paciente: %s\nFaixa de Risco: excesso de peso.\n",nome); }
     
     if (imc>20.0 & imc<=35.0) { printf ("\nNome do paciente: %s\nFaixa de Risco: obesidade.\n",nome); }
     
     if (imc>35.0) { printf ("\nNome do paciente: %s\nFaixa de Risco: abaixo do peso ideal.\n",nome); }

     fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux
     getchar();     

}
