#include <stdio.h>
int main (void) {
    float p, i, I, n, VA;
    printf ("\n ** Calculo do rendimento de uma poupança **\n\n");
    printf ("Informe a aplicação mensal: ");
    scanf ("%f", &p);
    printf ("Informe a taxa de juros da poupança aplicada: ");
    scanf ("%f", &I);
    printf ("Informe o numero de meses aplicados: ");
    scanf ("%f", &n);
    i = I/100.0;
    VA = (((pow(1.0+i,n))-1.0)/i)*p;
    printf ("O valor acumulado é de: %.2f reais.\n\n",VA);
    printf ("\n<< Marco Tulio>>\n");
    getchar(),getchar();
}
