#include <stdio.h>
int main (void) {
    int N,C,D,U;
    printf ("\n ** Inversor de numeros de 3 digitos **\n\n");
    printf ("Informe um numero de 3 digitos >=1,<=999 com o primeiro diferente de 0: ");
    scanf ("%i", &N);
    C = N/100;
    D = (N%100)/10;
    U = ((N%100)%10)/1;
    printf ("\nO inverso do numero %i é: %i%i%i.\n\n",N,U,D,C);
    printf ("<< Marco Tulio >>\n");
    getchar(),getchar();
}
