#include <stdio.h>
main () {
	long int data, dia, mes, ano;
	printf ("\nInforme uma data para consistir: ");
	scanf ("%i", &data);
	dia = ((data%10000000)*10) + ((data%10000000)/1000000);
	mes = ((((data%10000000)%1000000)/100000)*10) + ((((data%10000000)%1000000)%100000)/10000);
	ano = ( ((((((data%10000000)%1000000)%100000)%10000)/1000)*1000) + (((((((data%10000000)%1000000)%100000)%10000)%1000)/100)*100) + ((((((((data%10000000)%1000000)%100000)%10000)%1000)%100)/10)*10) + ((((((((data%10000000)%1000000)%100000)%10000)%1000)%100)%10)*1) );
	if ( (ano >= 1000) && (ano<=2999) && (mes>=1) && (mes<=12) && (dia>=1) && (dia<=30) ) {
		printf ("\n\n\tA data %.0li/%.0li/%0li é valída!\n\n",dia,mes,ano);
	}
	else printf ("\n\n\tData Invalida!!!\n\n");
	
}