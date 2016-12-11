/*Marco Tulio*/

#include <stdio.h>
main () {
     printf ("\n\t\t\tExercicio 09 - Lista 02\n\n");
     float sl, slr;
     printf ("Digite o salario do funcionario: ");
     scanf ("%f", &sl);
     if ( sl <=350.0 ) {
          slr = 1.5*sl;
     }
     else slr = 1.3*sl;
     printf ("\nO Salario reajustado do funcionario é de %.2f Reais.\n\n",slr);
     getchar();
     getchar();
}
