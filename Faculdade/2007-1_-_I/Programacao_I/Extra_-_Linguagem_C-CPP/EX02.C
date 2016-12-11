#include <stdio.h>
int main (void) {
  float ni, n1, n2, n3, me, ma;
  printf ("\nDigite o numero de indentificação do aluno: ");
  scanf ("%f", &ni);
  printf ("Digite a Nota 1: ");
  scanf ("%f", &n1);
  printf ("Digite a Nota 2: ");
  scanf ("%f", &n2);
  printf ("Digite a Nota 3: ");
  scanf ("%f", &n3);
  printf ("Digite a Media dos exercicios: ");
  scanf ("%f", &me);
  ma = (n1 + n2*2 + n3*3 + me)/7.0;
  if (ma >= 9.1 && ma <= 10.0) {
    printf ("\n\tO Numero de Identificação do aluno é %.0f.\n\tO aluno foi APROVADO com a Media de Aproveitamento %.2f e com Conceito A.\n\n",ni, ma);
  }
  if (ma >= 7.6 && ma <= 9.0) {
    printf ("\n\tO Numero de Identificação do aluno é %.0f.\n\tO aluno foi APROVADO com a Media de Aproveitamento %.2f e com Conceito B.\n\n",ni, ma);
  }
  if (ma >= 6.1 && ma <= 7.5) {
    printf ("\n\tO Numero de Identificação do aluno é %.0f.\n\tO aluno foi APROVADO com a Media de Aproveitamento %.2f e com Conceito C.\n\n",ni, ma);
  }
  if (ma >= 4.1 && ma <= 6.0) {
    printf ("\n\tO Numero de Identificação do aluno é %.0f.\n\tO aluno foi REPROVADO com a Media de Aproveitamento %.2f e com o Conceito D.\n\n",ni, ma);
  }
  if (ma < 4.0) {
    printf ("\n\tO Numero de Identificação do aluno é %.0f.\n\tO aluno foi REPROVADO com a Media de Aproveitamento %.2f e com o Conceito E.\n\n",ni, ma);
  }
}
