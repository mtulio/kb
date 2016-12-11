                    /*Marco Tulio*/
/*VERIFICAR*/


#include <stdio.h>
#include <string.h>
main () {
     char opt[4]; //moeda[15];
     float qtreais, convert;
     printf ("\n\t\t\tExercicio 39 - Lista 02\n\n");
     printf ("Digite uma Quantia em reais para Conversão: ");
     scanf ("%f", &qtreais);
     printf ("\t(E)uro            R$ 2,617\n\t(L)ibra Esterlina R$ 3,816\n\t(D)olar           R$ 2,071\n\t(I)ene            R$ 0,018\nInforme a Moeda: ");
     scanf ("%s", &opt);
     
    //printf ("%f\n%s",qtreais, opt);
    
    
     if ( strcmp(opt,'E')==0 || !strcmp(opt,'e')==0 ) {
          convert = qtreais/2.617;
          //strcpy(moeda,"Euro(s)");
          printf ("\nO Valor convertido é de %.2f, Euro(s)\n",convert);
     }
     
     if ( strcmp(opt,'L') && strcmp(opt,'l')) {
          convert = qtreais/3.816;
          //strcpy(moeda,"Libra(s)");
          printf ("\nO Valor convertido é de %.2f, Libra(s)\n",convert);
     }
     
     if ( strcmp(opt,'D') & strcmp(opt,'d') ) {
          convert = qtreais/2.071;
          //strcpy(moeda,"Dolar(es)");
          printf ("\nO Valor convertido é de %.2f, Dolar(es)\n",convert);
     }
     
     if ( strcmp(opt,'I') & strcmp(opt,'i') ) {
          convert = qtreais/0.018;
          //strcpy(moeda,"Iene(s)");
          printf ("\nO Valor convertido é de %.2f, Iene(s)\n",convert);
     }
           
     getchar();
     getchar();
}
