#include <stdio.h>
int main (void) {
    float VCD,TD,ICMS,PLE,VP,VR;
    printf ("\n ** Calculo do valor de uma compra em Dolares ** \n\n");
    printf ("Informe o valor da compra, em dolares, em reais: ");
    scanf ("%f", &VCD);
    printf ("Informe a taxa de Dolar no dia da compra: ");
    scanf ("%f", &TD);
    printf ("Informe o valor do ICMS: ");
    scanf ("%f", &ICMS);
    printf ("Informe o percentual de lucro da empresa: ");
    scanf ("%f", &PLE);
    VR = VCD * TD;
    VP = VR + VR*ICMS / 100.0 + VR*PLE / 100.0;
    printf ("\nO valor a ser pago é: %f Reais.\n\n",VP);
    printf ("<< Marco Tulio >>\n");
    getchar(),getchar();
}
