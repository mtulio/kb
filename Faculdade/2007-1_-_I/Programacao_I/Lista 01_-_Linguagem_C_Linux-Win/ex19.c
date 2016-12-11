#include <stdio.h>
int main (void){
  float D,V,Cm;
  printf ("\n** Calculo do consumo medio de um carro **\n\n");
  printf ("Informe a distancia percorrida,em Km: ");
  scanf ("%f", &D);
  printf  ("Digite a quantidade de litros: ");
  scanf ("%f", &V);
  Cm = D/V;
  printf ("\nO consumo medio do carro para a distancia de %.2f Km é %.2f km/l.",D,Cm);
  printf ("\n\n<< Marco Tulio >>\n");
  getchar(),getchar();
}
