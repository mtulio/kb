                        /*Marco Tulio*/

#include<stdio.h>
#include<string.h>
int main (void) {
    char nome[20];
    int tplig ;
    float vlpg, min;
    printf ("\n\t\t\tExercicio 30 - Lista 02\n\n");
    printf ("Informe o nome do Usuario: ");
    gets(nome);
    printf ("Digite o tempo da ligação, em minutos: ");
    scanf ("%f", &tplig);
  
    if ( (tplig/3.0)==0 ) {
       vlpg = 2.0+1.0;
    }
    if ((tplig%5)==0) { 
       vlpg = 2.0 + ((tplig/5.0)*2.15);
    }
    if ((tplig%5)!=0) {
       vlpg = 2.0 + ((tplig%5)*0.85); 
    }   
    printf ("\nNome do Usuario: %s\nValor da Conta: R$%.2f\n\n",nome, vlpg);
    
    fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux
     getchar();
    
}
