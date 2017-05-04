#include<stdio.h>

int main (void){

int cont1;

scanf("%d",&cont1);
printf("qualquer texto\n");

cont1 = 55;

if( cont1 > 9999 ){

	cont1 = 222 + 222 ;

}
else
	printf("erro\n");

exit(0);

}
