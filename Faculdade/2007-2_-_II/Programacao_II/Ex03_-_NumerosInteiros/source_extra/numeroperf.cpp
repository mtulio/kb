#include<stdio.h>
main ()
{
int  t, n, sdiv;

printf("Digite um numero= ");
scanf("%i", &n);
t=n-1;//Condi��o p/ qdo o la�o for executado n haver divis�o por 0
sdiv=0;//soma dos divisores do numero


while(t>0){
           if((n%t)==0){//encontrando os divisores e fazendo a somatoria
                          sdiv = t+ sdiv; 
           }
           t--;
}

if (n==sdiv) printf("\nnumero perfeito\n");
else printf ("\n n eh numero perfeito\n");


getchar();
getchar();
}
