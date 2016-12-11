                        /*Marco Tulio*/

#include <stdio.h>
#include<string.h>
int main (void) {
    char nome[20];
    printf ("\n\t\t\tExercicio 28 - Lista 02\n\n");
    printf ("Digite o nome do aluno: ");
    scanf ("%s", &nome);
    
    //condição 01:
    if ( ((nome[0]>='A') && (nome[0]<='K')) || ((nome[0]>='a') && (nome[0]<='k')) ) {
                printf ("\nAluno: %s \nLocal da Prova: Bloco F - Sala 101\n",nome);
    }
    
    //condição 02:
    if ( ((nome[0]>='L') && (nome[0]<='N')) || ((nome[0]>='l') && (nome[0]<='n')) ) {
            printf ("\nAluno: %s \nLocal da Prova: Bloco F - Sala 102.\n",nome);
    }
    
    //condição 03:
    if ( ((nome[0]>='O') && (nome[0]<='Z')) || ((nome[0]>='o') && (nome[0]<='z') )) {
         printf ("\nAluno: %s \nLocal da Prova: Bloco F - Sala 103.\n",nome);
    }
    
    getchar();
    getchar();
}
