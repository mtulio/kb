#include <stdio.h>
int main (void) {
    float p, i, I, n, VA;
    printf ("\n ** Calculo do rendimento de uma poupan�a **\n\n");
    printf ("Informe a aplica��o mensal: ");
    scanf ("%f", &p);
    printf ("Informe a taxa de juros da poupan�a aplicada: ");
    scanf ("%f", &I);
    printf ("Informe o numero de meses aplicados: ");
    scanf ("%f", &n);
    i = I/100.0;
    VA = (((pow(1.0+i,n))-1.0)/i)*p;
    printf ("O valor acumulado � de: %.2f reais.\n\n",VA);
    printf ("\n<< Marco Tulio>>\n");
    getchar(),getchar();
}
