                        /*Marco Tulio*/

#include <stdio.h>
#include <string.h>
int main (void) {
	printf ("\n\t\t\tExercicio 22 - Lista 02\n\n");
    float n1, n2, result;
	char operacao[2];
	printf ("\nDigite o primeiro numero p/calcular: ");
	scanf ("%f", &n1);
	printf ("Digite o segundo numero p/calcular: ");
	scanf ("%f", &n2);
	printf ("Opera��es:\n\t(+)-Adi��o;\n\t(-)-Subtra��o;\n\t(*)-Multiplica��o;\n\t(/)-Divis�o;\nDigite a opera��o desejada: ");
	scanf ("%s", &operacao);
	if (strcmp (operacao,"+")==0 ) {
	   result = n1 + n2;
    }
    if (strcmp (operacao,"-")==0 ) {
       result = n1 - n2;
    } 
    if (strcmp (operacao,"*")==0) {
	   result = n1 * n2;
    }    
    if (strcmp (operacao,"/")==0) {
	   result = n1 / n2;
    }
    printf ("\n\nO resultado da opera��o desejada � %.2f.\n",result);
    getchar();
    getchar();
}
