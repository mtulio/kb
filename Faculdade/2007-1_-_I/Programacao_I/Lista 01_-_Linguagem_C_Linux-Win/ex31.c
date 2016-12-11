#include <stdio.h>
int main (void){
    printf ("\n ** Troca de Numeros informados ** \n\n");
    float A,B,AB,BA;
    printf ("Informe um numero: ");
    scanf ("%f", &A);
    printf ("Informe outro numero: ");
    scanf ("%f", &B);
    AB = B;
    BA = A;
    printf ("\nO valor trocado dos numeros informados é, respectivamente: %.0f, %.0f.\n\n",AB,BA);
    printf ("<<Marco Tulio>>\n");
    getchar(),getchar();
}
