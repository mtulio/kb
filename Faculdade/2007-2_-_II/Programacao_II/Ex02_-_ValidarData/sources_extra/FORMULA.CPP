//S = y - 7 * INT[y/7]
//y = d + INT[(13m - 1)/5] + a + INT[a/4] + INT[c/4] - 2c

#include <stdio.h>
#include <math.h>

int main(void){

    int y;
    int ano, dia, mes,a,c,S; 
    printf("Digite o dia: ");
    scanf ("%i",&dia);
    printf ("digite o mes: ");
    scanf("%i", &mes);
    printf ("digite o ano: ");
    scanf ("%i", &ano);

    a=ano/100;
    c=ano%100;
     y = dia + ((13*mes - 1)/5) + ano + (a/4) + (c/4) - 2*c;
     S = y - 7*(y/7);
   
                

printf ("\ndia da semana = %i ",S);

switch(S) {
          case 1:
               printf ("\n\t\tDomingo");
               break;
          case 2:
               printf ("\n\t\tSegunda-feira");
               break;
          case 3:
               printf ("\n\t\tTerça-Feira");
               break;
          case 4:
               printf ("\n\t\tQuarta-Feira");
               break;
          case 5:
               printf ("\n\t\tQuinta-Feira");
               break;
          case 6:
               printf ("\n\t\tSexta-Feira");
               break;
          case 0:
               printf ("\n\t\tSabado");
               break;
          }
          

getchar();
getchar();
}
