#include <stdio.h>
int main (void) {
    printf ("\n ** Calculo da diaria, valor medio, lucro e prejuizo da promoção no Hotel **\n\n");
    float vdn, vdp, vmasp, vmacp, lpm;
    printf ("Informe o valor, em reais, da diaria normal do Hotel: ");
    scanf ("%f", &vdn);
    vdp = 0.78*vdn;
    vmasp = vdn*18.0*30.0;
    vmacp = vdp*29.0*30.0;
    lpm = vmacp - vmasp;
    printf ("\nO valor da diaria no periodo da promoção é, em Reais: %.2f;\n", vdp);
    printf ("O valor medio arrecadado sem a promoção durante 1 mês é, em Reais: %.2f;\n", vmasp);
    printf ("O valor medio arrecadado com a promoção durante 1 mês é, em Reais: %.2f;\n", vmacp);
    printf ("O lucro, se positivo, ou prejuizo, se negativo, com a promoção é, em Reais: %.2f.\n", lpm);
    printf ("\n\n<<Marco Tulio>>\n");
    getchar(),getchar();
}
    
    
