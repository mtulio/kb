#include <stdio.h>
int main (void) {
    printf ("\n ** Calculo de aluguel de carros ** \n");
    float td,tk,nd,nkr,tp,vd;
    printf ("\nInforme a taxa diaria de aluguel: ");
    scanf ("%f", &td);
    printf ("Informe a taxa por Kilometro rodado: ");
    scanf ("%f", &tk);
    printf ("Informe o numero de dias alugados: ");
    scanf ("%f", &nd);
    printf ("Informe o numero de Kilometros rodados: ");
    scanf ("%f", &nkr);
    tp = td*nd + tk*nkr - (td*nd)*0.10;
    vd = (td*nd)*0.10;
    printf ("\nO valor total do  aluguel é: %.2f Reais.\n",tp);
    printf ("O valor   do   desconto   é: %.2f Reais.\n",vd);
    printf ("O numero de dias alugados é: %.0f Dias.\n",nd);
    printf ("A quilometragem  rodada   é: %.2f Km.\n",nkr);
    printf ("\n\n<<Marco Tulio>>\n");
    getchar(),getchar();
}
