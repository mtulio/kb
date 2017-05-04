#include <stdio.h>
#include<string.h>
main () {


 int  t, n, contDiv;

 printf("Digite o valor de n: ");
 scanf("%i", &n);

      t=n;//concatenando valores na var temporaria
      contDiv=0;//Contador do numero de divisores
      while(t>0){
          if((n%t)==0){//encontrando o numero de divisores
                  contDiv++; 
            }
            t--;printf ("\n\nContador de divisoes: %i\n",contDiv);
      }
     if (n%1==0 && n%n==0 && contDiv==2) printf("\n eh numero primo\n");
      else printf("\n n eh numero primo\n");
      
      getchar();
      getchar();
      
      
}
