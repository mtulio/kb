#include<stdio.h>

int main (void){

int var1, var2, var3, var4, var5, var6;

scanf("%d",&var1);
printf("Sistema de Atrib de variaveis - Comparando vars\n");

var2 = var1;

var3 = var2;

var4 = var3;

var5 = var4;

var6 = 6;

if( var5 > var6 ){

	var5 = var5 * 2 + var6 - var1 ;

}
else
	printf("erro do senao\n");

exit(0);

}
