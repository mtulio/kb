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
	printf ("Operações:\n\t(+)-Adição;\n\t(-)-Subtração;\n\t(*)-Multiplicação;\n\t(/)-Divisão;\nDigite a operação desejada: ");
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
    printf ("\n\nO resultado da operação desejada é %.2f.\n",result);
    getchar();
    getchar();
}
