#include <stdio.h>
int main (void) {
    printf ("\n ** Pre�o de Custo e Venda de uma receita de p�o franc�s ** \n\n");
    float qkf, vkf, qld, vld, qkwh, vkwh, vimp, Imposto, PC, PV;
    printf ("Informe a quantidade de quilos de farinha: ");
    scanf ("%f", &qkf);
    printf ("Informe o valor do quilo da farinha: ");
    scanf ("%f", &vkf);
    printf ("Informe a quantidade de litros d'agua: ");
    scanf ("%f", &qld);
    printf ("Informe o valor do litro d'agua: ");
    scanf ("%f", &vld);
    printf ("Informe a quantidade de Quilowatts hora de energia: ");
    scanf ("%f", &qkwh);
    printf ("Informe o valor do Quilowatt hora: ");
    scanf ("%f", &vkwh);
    printf ("Informe o valor percentual do imposto: ");
    scanf ("%f", &vimp);
    Imposto = (qkf*vkf + qld*vld + qkwh*vkwh)*vimp/100.0;
    PC = qkf*vkf + qld*vld + qkwh*vkwh + Imposto;
    PV = PC * 1.30;
    printf ("\nO pre�o de custo do p�o �: %.2f Reais.\n",PC);
    printf ("O pre�o de venda do p�o �: %.2f Reais.\n",PV);
    printf ("\n\n<<Marco Tulio>>\n");
    getchar(),getchar();
}
    
    
