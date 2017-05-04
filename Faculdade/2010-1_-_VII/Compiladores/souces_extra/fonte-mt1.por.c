#include<stdio.h>

int main (void){

int var1, var2, var3, var4;

scanf("%d",&var1);
scanf("%d",&var2);
printf("%d",var1);
scanf("%d",&var3);
printf("Teste texto qualquer\n");
scanf("%d",&var4);
printf("%d",var4);

var1 = 1;
var2 = var3;

var4 = 4;

if( var1 > 0 ){

	var2 = var1 + 1 - 1 * 2 ;

}
else