/*Marco Tulio*/

#include <stdio.h>
int main (void) {
    printf ("\n\t\t\tExercicio 20 - Lista 02\n\n");
    int diasm, tl;
    float pn, tp;
    printf ("\nDigite o pre�o normal da fita: ");
    scanf ("%f", &pn);
    printf ("\n\t(1)-Domingo;\n\t(2)-Segunda;\n\t(3)-Ter�a;\n\t(4)-Quarta;\n\t(5)-Quinta;\n\t(6)-Sexta;\n\t(7)-Sabado.\nDigite o dia da loca��o: ");
    scanf ("%i", &diasm);
    printf ("\nTipos de Loca��o:\n\t(1)-Normal;\n\t(2)-Lan�amento.\nDigite o tipo de loca��o: ");
    scanf ("%d", &tl);
    switch (diasm) {
           case 2:
           case 3:
           case 5:
                switch (tl){
                       case 1:
                            tp = 0.60*pn;
                            break;
                       case 2:
                            tp = (1.15*pn)*0.60;
                            break;
                }
           break;
           case 1:
           case 4:
           case 6:
           case 7:
                switch (tl){
                       case 1:
                            tp = pn;
                            break;
                       case 2:
                            tp = 1.15*pn;
                            break;
                }
           break;
           default :
                   printf ("\n\t\tOp��o Invalida, TENTE NOVAMENTE!!!\n\n");
    }
    printf ("\n\n\t\tO total a pagar � de R$ %.2f .\n\t",tp);
    getchar();
    getchar();
}
