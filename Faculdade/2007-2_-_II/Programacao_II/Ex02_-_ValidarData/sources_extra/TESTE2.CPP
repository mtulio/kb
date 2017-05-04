#include <stdio.h>
#include <math.h>

int main(void){
int mesS, ano1, ano2, anoS1, anoS2, diaSemana, ano, dia, mes; 
//float 
printf("Digite o dia: ");
scanf ("%i",&dia);
printf ("digite o mes: ");
scanf("%i", &mes);
printf ("digite o ano: ");
scanf ("%i", &ano);


mesS = int((2.6*mes-0.2)/1);
ano1 = int(ano%100);
ano2 = int(ano/100);

anoS1 = int(ano1/4.0);
anoS2 = int(ano2/4.0);

diaSemana = int((mesS + dia + anoS1 + anoS2 - 2*anoS2)%7);
                   
//dia da semana = resto( quociente((2,6*M-0,2),1) +D+A+ Quociente(A,4)+Quociente(S,4) - 2*S) ,7)

printf ("\ndia da semana = %i ",anoS2);

getchar();
getchar();
}
