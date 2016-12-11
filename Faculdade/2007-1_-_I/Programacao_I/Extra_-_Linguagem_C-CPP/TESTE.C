#include <stdio.h>
#include <stdlib.h>
int main (void) {
  float N,H,VH,F,SF,ST;
  int i=0;
  do{ 
  printf ("\n\n** Calculo do salario de um funcionario **\n\n");
  printf ("Digite o numero do funcionario: ");
  scanf ("%f", &N);
  printf ("Digite o numero de horas trabalhadas: ");
  scanf ("%f", &H);
  printf ("Digite o valor recebido por hora: ");
  scanf ("%f", &VH);
  printf ("Qual a quantidade de filhos < ou = à 14 anos: ");
  scanf ("%f", &F);
  printf ("Informe o valor do salario familia: ");
  scanf ("%f", &SF);
  if (F<=14)
  ST = H * VH + (F <=14) * SF;
  printf ("\nO numero do funcionario é: %.0f.\n",N);
  printf ("O salario total do funcionario é: %.2f\n",ST);
  printf ("\n<< Marco Tulio >>\n");
  i++;
  }while(i<3);
 
 
 // system ("clear");
}
