#include <stdio.h>
int main (void) {
    printf ("\n ** Calculo da diaria, valor medio, lucro e prejuizo da promo��o no Hotel **\n\n");
    float vdn, vdp, vmasp, vmacp, lpm;
    printf ("Informe o valor, em reais, da diaria normal do Hotel: ");
    scanf ("%f", &vdn);
    vdp = 0.78*vdn;
    vmasp = vdn*18.0*30.0;
    vmacp = vdp*29.0*30.0;
    lpm = vmacp - vmasp;
    printf ("\nO valor da diaria no periodo da promo��o �, em Reais: %.2f;\n", vdp);
    printf ("O valor medio arrecadado sem a promo��o durante 1 m�s �, em Reais: %.2f;\n", vmasp);
    printf ("O valor medio arrecadado com a promo��o durante 1 m�s �, em Reais: %.2f;\n", vmacp);
    printf ("O lucro, se positivo, ou prejuizo, se negativo, com a promo��o �, em Reais: %.2f.\n", lpm);
    printf ("\n\n<<Marco Tulio>>\n");
    getchar(),getchar();
}
    
    
