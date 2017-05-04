/*Marco Tulio*/
/*Analizar programa...está imprimindo o valor negativo*/

#include <stdio.h>
main () {
     printf ("\n\t\t\tExercicio 17 - Lista 02\n\n");
     float nd, slf, imn, imbruto1, imbruto, txadicional,imliquido, impagar;
     printf ("\nDigite o numero de dependentes do funcionario: ");
     scanf ("%f", &nd);
     printf ("Digite o salario do funcionario: ");
     scanf ("%f", &slf);
     printf ("Digite o Imposto normal pago pelo funcionario: ");
     scanf ("%f", &imn);
     if ( ((slf/350.0) > 12.0) || ((slf/350.0)>=5.0) || ((slf/350.0)<12.0) ) {
          if ((slf/350.0)>12.0 ) {
                           imbruto1 = 0.20*slf;
          }
           if ( ((slf/350.0)>=5.0) && ((slf/350.0)<12.0) ) {
               imbruto1 = 0.08*slf;
               }
     imbruto = imbruto1 - (300.0)*nd;
     txadicional = 0.04*imbruto1;
     imliquido = imbruto + txadicional;
     impagar = imn - imliquido;
     if (impagar <= 1.0) {
        printf ("\n\tImposto à pagar no valor de R$ %.2f.\n\n",-1*impagar);
     }
     else{ if  (impagar>=1) { printf ("\n\tImposto à receber no valor de R$ %.2f.\n\n",impagar);
           } 
           else if (impagar==0) printf ("\n\tSem Divida com o Governo!\n\n"); 
     } 
     
     }
     getchar();
     getchar();
}
