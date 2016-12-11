/*Marco Tulio*/

#include <stdio.h>
int main (void) {
    printf ("\n\t\t\tExercicio 02 - Lista 02\n\n");
    float n1, n2, n3, md;
    printf ("\nDigite a 1º nota: ");
    scanf ("%f", &n1);
    printf ("Digite a 2º nota: ");
    scanf ("%f", &n2);
    printf ("Digite a 3º nota: ");
    scanf ("%f", &n3);
    md = (n1 + n2 + n3 )/3.0;
    if (md >= 6.0) {
           printf ("\n\tO aluno foi APROVADO com a Media %.2f.",md);
    }
    else printf ("\n\tO Aluno foi REPROVADO com a Media %.2f.",md);
    getchar();
    getchar();
}
