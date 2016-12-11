#include <stdio.h>
int main (void) {
    printf ("\n ** Calculadora da renda total de um jogo **\n\n");
    float PT,PP,GL,AQ,CD,TP;
    printf ("Informe o publico total do jogo: ");
    scanf ("%f", &PT);
    PP = 0.10*PT*1.00;
    GL = 0.50*PT*5.00;
    AQ = 0.30*PT*10.00;
    CD = 0.10*PT*20.00;
    TP = PP+GL+AQ+CD;
    printf ("A renda total do jogo é %.2f Reais.\n",TP);
    printf ("\n<<Marco Tulio>>\n");
    getchar(),getchar();
}
