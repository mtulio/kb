// Obs: o exercicios diz pra ler a op��o com os simbolos mas o programa l� com numeros definidos pelo usuario
#include <stdio.h>
int main (void){
    float n1, n2, result, oper;
    printf ("\nDigite o primerio numero, diferente de 0: ");
    scanf ("%f", &n1);
    printf ("Digite o segundo numero, diferente de 0: ");
    scanf ("%f", &n2);
    printf ("Escolha a opera��o:\n\t(1)-Adi��o;\n\t(2)-Subtra��o;\n\t(3)-Multiplica��o;\n\t(4)-Divis�o;\n\t\tDigite: ");
    scanf ("%f", &oper);
    if (oper == 1) result = n1+n2;
    if (oper == 2) result = n1-n2;
    if (oper == 3) result = n1*n2;
    if (oper == 4) result = n1/n2;
    printf ("\n\n\t\t\tO valor da opera��o desejada � %.2f.\n\n",result);
}
