#include<stdio.h>

int main (void){

int cont1, cont2;

scanf("%d",&cont1);
scanf("%d",&cont2);
printf("teste\n");
scanf("%d",&cont2);
printf("teste2\n");
scanf("%d",&cont2);
printf("%d",cont2);

cont1 = cont1;

cont2 = cont1;
if( cont1 >= cont2 ){

	cont1 = cont2 + 1 * 1 - cont2 ;
