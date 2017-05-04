#include<stdio.h>
int main (void) {
	int optexe, fimprogr, inicio;
	printf ("\nBem Vindo Marco Tulio\n\n");
	printf ("\n\t\tProgramação I - Lista 02\n\n");
	
        volta:
	
	
	printf ("(01)-Exercicio 01\t(02)-Exercicio 02\t(03)-Exercicio 03\n(04)-Exercicio 04\t(05)-Exercicio 05\t(06)-Exercicio 06\n(07)-Exercicio 07\t(08)-Exercicio 08\t(09)-Exercicio 09\n(10)-Exercicio 10\t(11)-Exercicio 11\t(12)-Exercicio 12\n(13)-Exercicio 13\t(14)-Exercicio 14\t(15)-Exercicio 15\n(16)-Exercicio 16\t(17)-Exercicio 17\t(18)-Exercicio 18\n(19)-Exercicio 19\t(20)-Exercicio 20\nQual exercicio vc deseja executar?: ");
	scanf ("%i", &optexe);
	
	switch (optexe) {
		case 1:
			system ("ex01");
			break;
		case 18:
			printf ("\n\t\t\t\tEXERCICIO 18\n");
			system ("./ex18");
			break;
	}
	
	printf ("\n\t(1)Retornar ao menu\n\t(0)-Sair do Sistema\nO que deseja fazer?: ");
	scanf ("%i", &fimprogr);
	
	switch (fimprogr) {
		case 1:
			system ("clear");
                        goto volta;
			break;	
		case 2:
			system ("clear");
			return;
			break;
	}
	
	getchar();
	getchar();
	system ("clear");
}
