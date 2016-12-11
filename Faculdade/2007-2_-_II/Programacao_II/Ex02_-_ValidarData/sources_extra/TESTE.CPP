#include<stdio.h>
#include<math.h>

int main (void) {
//    int dia, mes, ano, ano1, ano2, diaSemana;
    int numInf, nfinal;
    float operacao;
  
  printf ("Digite o mes: ");
  scanf ("%i", &numInf);
  /*  
    printf ("\ndigite o dia: ");
    scanf ("%i", &dia);
    printf ("\ndigite o mes: ");
    scanf ("%i", &mes);
    printf ("\ndigite o ano: ");
    scanf ("%i", &ano);

ano1=ano/100;
ano2=ano%100;

diaSemana= ( ((2.6*mes)-0,2)/1 + dia + ano2 + (ano2/4) + (ano1/4) - 2*ano2 )%7;
    */
   operacao = 2.6*numInf;
    

    printf ("Resultado = %f", floor(operacao));
    
    
    getchar();
    getchar();
}
