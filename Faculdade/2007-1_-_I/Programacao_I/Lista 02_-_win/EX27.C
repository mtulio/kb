                        /*Marco Tulio*/

#include <stdio.h>
#include <math.h>
int main (void) {
    printf ("\n\t\t\tExercicio 27 - Lista 02\n\n");
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
       printf ("\n\tCodigo do Aluno: %.0f.\n\tNota 1: %.2f\n\tNota 2: %.2f\n\tNota 3: %.2f\n\tMedia dos Exercicios: %.2f\n\tConceito A\n\tAPROVADO com a Media de Aproveitamento %.2f.\n\n",ni, n1, n2, n3, me, ma);
    }
    if ( (ma >= 7.6) && (ma<= 9.0) ) {
       printf ("\n\tCodigo do Aluno: %.0f.\n\tNota 1: %.2f\n\tNota 2: %.2f\n\tNota 3: %.2f\n\tMedia dos Exercicios: %.2f\n\tConceito B\n\tAPROVADO com a Media de Aproveitamento %.2f.\n\n",ni, n1, n2, n3, me, ma);
    }
    if (( ma >= 6.1) && (ma<= 7.5) ) {
       printf ("\n\tCodigo do Aluno: %.0f.\n\tNota 1: %.2f\n\tNota 2: %.2f\n\tNota 3: %.2f\n\tMedia dos Exercicios: %.2f\n\tConceito C\n\tAPROVADO com a Media de Aproveitamento %.2f.\n\n",ni, n1, n2, n3, me, ma);
    }
    if ( (ma >= 4.1) && (ma<= 6.0) ) {
       printf ("\n\tCodigo do Aluno: %.0f.\n\tNota 1: %.2f\n\tNota 2: %.2f\n\tNota 3: %.2f\n\tMedia dos Exercicios: %.2f\n\tConceito D\n\tREPROVADO com a Media de Aproveitamento %.2f.\n\n",ni, n1, n2, n3, me, ma);
    }
    if ( ma < 4.1) {
       printf ("\n\tCodigo do Aluno: %.0f.\n\tNota 1: %.2f\n\tNota 2: %.2f\n\tNota 3: %.2f\n\tMedia dos Exercicios: %.2f\n\tConceito E\n\tREPROVADO com a Media de Aproveitamento %.2f.\n\n",ni, n1, n2, n3, me, ma);
    }
    getchar();
    getchar();
}
