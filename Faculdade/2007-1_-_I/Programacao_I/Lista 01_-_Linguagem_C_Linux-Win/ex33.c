#include <stdio.h>
int main (void) {
    printf ("\n ** Calculo da media ponderada da disciplina de Programação de Compuradores **\n");
    float n1,n2,n3,n4,P;
    printf ("\nInforme a nota da 1 avaliação: ");
    scanf ("%f", &n1);
    printf ("Informe a nota da 2 avaliação: ");
    scanf ("%f", &n2);
    printf ("Informe a nota da 3 avaliação: ");
    scanf ("%f", &n3);
    printf ("Informe a nota da 4 avaliação: ");
    scanf ("%f", &n4);
    P = (n1*2.0+n2*4.0+n3*6.0+n4*8.0)/(2.0+4.0+6.0+8.0);
    printf ("\nA media Ponderada do aluno da seguinte disciplina é: %.2f.\n",P);
    printf ("\n<<Marco Tulio>>\n");
}
