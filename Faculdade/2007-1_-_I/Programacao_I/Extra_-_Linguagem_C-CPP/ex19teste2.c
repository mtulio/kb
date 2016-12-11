                     /*Marco Tulio*/

/*VERIFICAR: 04101988 = DATA invalida?! FAlsoooo*/

#include <stdio.h>
main () {
	long int data, dia, mes, ano;
	printf ("\n\t\t\tExercicio 19 - Lista 02\n\n");
    printf ("\nInforme um dia para consistir: ");
    scanf ("%li", &dia);
    printf ("\nInforme um mes para consistir: ");
    scanf ("%li", &mes);
    printf ("\nInforme um mes para consistir: ");
    scanf ("%li", &ano);    
    
   if (dia <=0 || dia >31 || mes <01 || mes>12 || ano<0 || ano>10000) {
		printf ("\n\n\tData Invalida!!!\n\n");
	}
	else printf ("\n\n\tA data %.0li/%.0li/%0li é valida!\n\n",dia,mes,ano);
	
//    fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux

	getchar();
	getchar();


}
