#include <stdio.h>
int main (void){
  float IPI,CD1,VL1,QTD1,CD2,VL2,QTD2,VT;
  printf ("\n** Calculo do valor de IPI **\n\n");
  printf ("\nInforme valor do IPI: ");
  scanf ("%f",&IPI);
  printf ("Informe o codigo da pe�a tipo 1: ");
  scanf ("%f",&CD1);
  printf ("Informe o valor da pe�a tipo 1: ");
  scanf ("%f",&VL1);
  printf ("Informe a quantidade de pe�as tipo 1: ");
  scanf ("%f",&QTD1);
  printf ("Informe o codigo da pe�a tipo 2: ");
  scanf ("%f",&CD2);
  printf ("Informe o valor da pe�a tipo 2: ");
  scanf ("%f",&VL2);
  printf ("Informe a quantidade da pe�a tipo 2: ");
  scanf ("%f",&QTD2);
  VT = ( VL1*QTD1 + VL2*QTD2) * (IPI/100.0 + 1.0);
  printf ("\nO valor a ser pago �: %.2f reais.\n\n",VT);
  printf ("\n<< Marco Tulio >>\n");
  getchar(),getchar();
}

