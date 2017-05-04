#include <stdio.h>
#include <smath.h>
int main (void){
     float l1,l2,l3,A,T;
     printf (" \n** CALCULO DA AREA DE UM TRIANGULO** \n");
     printf ("\nInforme o primeito lado: ");
     scanf ("%f",&l1);
     printf ("Informe o segundo lado: ");
     scanf ("%f",&l2);
     printf ("Informe o terceiro lado: ");
     scanf ("%f",&l3);
     T = (l1 + l2 + l3) / 2.0;
     A = sqrt ( T * (T-l1)*(T-l2)*(T-l3) );
     printf ("\nA Area do triangulo e: %f. \n",A);
     printf ("\n\n<< Marco_Tulio >>\n");
}
