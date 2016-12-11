#include <stdio.h>
int main (void) {
    float pnf, dl, cf, tp;
    int i=0;
    printf ("Informe o preço normal da fita: ");
    scanf ("%f", &pnf);
    do{
    if (dl <1 || dl>7) printf ("\n\nVALOR INVALIDO, TENTE NOVAMENTE!!!\n\n\t\t");
    printf ("Informe o dia da locação:\n\t(1)-Domingo;\n\t(2)-Segunda;\n\t(3)-Terça;\n\t(4)-Quarta;\n\t(5)-Quinta;\n\t(6)-Sexta;\n\t(7)-Sabado.\n\t\tDigite: ");
    scanf ("%f", &dl);
    }while (dl<1 || dl>7);
    do{
    if (dl <1 || dl>2) printf ("\n\nVALOR INVALIDO, TENTE NOVAMENTE!!!\n\n\t\t");
    printf ("Informe a categoria do filme:\n\t(1)-Comum;\n\t(2)-Lançamento.\n\t\tDigite: ");
    scanf ("%f", &cf);
    }while (dl<1 || dl>2);
    if (dl == 1.0 && cf == 1.0) {
       tp = pnf;
    }
    if (dl == 1.0 && cf == 2.0) {
       tp = 1.13*pnf;
    }
    if (dl == 2.0 || dl == 3.0 || dl == 5.0 && cf == 1.0) {
       tp = 0.7*pnf;
    }
    if (dl == 2.0 || dl == 3.0 || dl == 5.0 && cf == 2.0) {
       tp = 0.7*pnf + (0.7*pnf)*0.13;
    }
    if (dl == 5.0 || dl == 6.0 || dl == 7.0 && cf == 1.0) {
       tp = 1.20*pnf;
    }
    if (dl == 5.0 && dl == 6.0 && dl == 7.0 && cf == 2.0) {
       tp = 1.20*pnf + (1.20*pnf)*0.13;
    }
    printf ("\n\t\t\tO Total a pagar é %.2f.\n\n", tp);
}
