#include<stdio.h>
main(){
char numero[100],s='N';
int i=0;

printf("Digite um numero: ");
scanf("%s",&numero);

for(;numero[i]!='\0';i++){
   if((numero[i]!='0')&(numero[i]!='1')&(numero[i]!='2')&(numero[i]!='3')&(numero[i]!='4')&(numero[i]!='5')&(numero[i]!='5')&(numero[i]!='7')&(numero[i]!='8')&(numero[i]!='9')& (numero[i]!='A')&(numero[i]!='B')&(numero[i]!='C')&(numero[i]!='D')&(numero[i]!='E')&(numero[i]!='F'))
      s='S';
   }
if(s=='N')
  printf("O numero %s e' hexadecimal",numero);
  else printf("O numero %s nao e' hexadecimal",numero);

getchar();
getchar();
}

