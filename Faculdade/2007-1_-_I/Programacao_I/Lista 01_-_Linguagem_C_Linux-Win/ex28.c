#include <stdio.h>
int main (void) {
    printf ("\n ** Gasto de um Refrigerador **\n\n");
    float P,T,QH,KWH,TP;
    printf ("Informe a potencia do refrigerador, em Watts: ");
    scanf ("%f", &P);
    printf ("Informe o tempo que permanece ligado, em Horas: ");
    scanf ("%f", &T);
    printf ("Informe o valor do Quilowatt Hora(KWH), em Reais: ");
    scanf ("%f", &QH);
    KWH = (P*T)/1000;
    TP = KWH*QH;
    printf ("\nA  energia   total    gasta    pelo   refrigerador   é: %.2f Kw/H.\n",KWH);
    printf ("O total à pagar para a companhia de Energia Eletrica é: %.2f Reais.\n",TP);
    printf ("\n\n<<Marco Tulio>>\n");
    getchar(),getchar();
}
