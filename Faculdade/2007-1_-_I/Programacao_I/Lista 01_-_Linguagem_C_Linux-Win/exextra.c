#include <stdio.h>
#include <string.h>
int main (void) {
    char nome[10],sobrenome[30],nome_completo[39];
    float n1, n2, nf;
    printf ("Digite o primeiro nome: ");
    scanf ("%s",&nome);
    printf ("Digite o sobrenome: ");
    scanf ("%s", &sobrenome);
    printf ("Digite a N1: ");
    scanf ("%f", &n1);
    printf ("Digite a N2: ");
    scanf ("%f", &n2);
    strcpy (nome_completo,nome);
    strcat (nome_completo," ");
    strcat (nome_completo,sobrenome);
    nf = n1*0.4 + n2*0.6;
    printf ("\nO aluno %s tem a media final de %.2f.\n",nome_completo, nf);
    getchar(),getchar();
}
