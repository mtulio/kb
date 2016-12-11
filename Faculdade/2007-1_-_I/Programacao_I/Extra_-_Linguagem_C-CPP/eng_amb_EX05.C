// Obs: o exercicios diz pra ler a opção com os simbolos mas o programa lê com numeros definidos pelo usuario
#include <stdio.h>
int main (void){
    float n1, n2, result, oper;
    printf ("\nDigite o primerio numero, diferente de 0: ");
    scanf ("%f", &n1);
    printf ("Digite o segundo numero, diferente de 0: ");
    scanf ("%f", &n2);
    printf ("Escolha a operação:\n\t(1)-Adição;\n\t(2)-Subtração;\n\t(3)-Multiplicação;\n\t(4)-Divisão;\n\t\tDigite: ");
    scanf ("%f", &oper);
    if (oper == 1) result = n1+n2;
    if (oper == 2) result = n1-n2;
    if (oper == 3) result = n1*n2;
    if (oper == 4) result = n1/n2;
    printf ("\n\n\t\t\tO valor da operação desejada é %.2f.\n\n",result);
}
