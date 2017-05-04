#include <stdio.h>
#include <math.h>
int main (void) {
    float ni, n1, n2, n3, ma, me;
    printf ("\nDigite o numero de Identificação do aluno: ");
    scanf ("%f", &ni);
    printf ("Digite a Nota 1: ");
    scanf ("%f", &n1);
    printf ("Digite a Nota 2: ");
    scanf ("%f", &n2);
    printf ("Digite a Nota 3: ");
    scanf ("%f", &n3);
    printf ("Digite a media dos exercicios: ");
    scanf ("%f", &me);
    ma = (n1+n2*2.0+n3*3.0+me)/7.0;
    if ( ma >= 9.1) {
         printf ("\n\tCodigo do Aluno: %.0f.\n\tO aluno foi APROVADO, Media de Aproveitamento %.2f, Conceito A.\n\n",ni, ma);
    }
    if ( ma >= 7.6 && <= 9.0) {
         printf ("\n\tCodigo do Aluno: %.0f.\n\tO aluno foi APROVADO, Media de Aproveitamento %.2f, Conceito B.\n\n",ni, ma);
    }
    if ( ma >= 6.1 && <= 7.5) {
         printf ("\n\tCodigo do Aluno: %.0f.\n\tO aluno foi APROVADO, Media de Aproveitamento %.2f, Conceito C.\n\n",ni, ma);
    }
    if ( ma >= 4.1 && <= 6.0) {
         printf ("\n\tCodigo do Aluno: %.0f.\n\tO aluno foi REPROVADO, Media de Aproveitamento %.2f, Conceito D.\n\n",ni, ma);
    }
    if ( ma < 4.0) {
         printf ("\n\tCodigo do Aluno: %.0f.\n\tO aluno foi REPROVADO, Media de Aproveitamento %.2f, Conceito E.\n\n",ni, ma);
    }
    getchar(),getchar();
}
