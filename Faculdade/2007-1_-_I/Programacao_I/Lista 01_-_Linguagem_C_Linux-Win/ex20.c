#include <stdio.h>
int main (void) {
  float N,H,VH,F,SF,ST;
  printf ("\n\n** Calculo do salario de um funcionario **\n\n");
  printf ("Digite o numero do funcionario: ");
  scanf ("%f", &N);
  printf ("Digite o numero de horas trabalhadas: ");
  scanf ("%f", &H);
  printf ("Digite o valor recebido por hora: ");
  scanf ("%f", &VH);
  printf ("Qual a quantidade de filhos < ou = � 14 anos: ");
  scanf ("%f", &F);
  printf ("Informe o valor do salario familia: ");
  scanf ("%f", &SF);
  ST = H * VH + (F <=14) * SF;
  printf ("\nO numero do funcionario �: %.0f.\n",N);
  printf ("O salario total do funcionario �: %.2f\n",ST);
  printf ("\n<< Marco Tulio >>\n");
  getchar(),getchar();
}
