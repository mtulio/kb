/*Marco Tulio*/

#include <stdio.h>
int main (void) {
	printf ("\n\t\t\tExercicio 01 - Lista 02\n\n");
    int n;
	printf ("\nDigite um nuemero: ");
	scanf ("%i", &n);
	if ( n%2 != 0 ) {
		printf ("\n\n\tO numero %i é IMPAR.\n\n",n);
	}
	else {
		printf ("\n\n\tO numero %i é PAR.\n\n",n);
	}
    fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux
    getchar();
}
