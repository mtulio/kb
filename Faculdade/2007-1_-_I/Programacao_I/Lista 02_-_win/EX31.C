                    /*Marco Tulio*/
                    
#include <stdio.h>
int main (void) {
    printf ("\n\t\t\tExercicio 31 - Lista 02\n\n");
    int idade;
    printf ("Digite a idade para verifica��o Eleitoral: ");
    scanf ("%i", &idade);
    if (idade <16) {
         printf ("\n\t\tN�o Eleitor!\n\n");
    }
    if ( (idade>=18) && (idade<65) ) {
         printf ("\n\t\tEleitor Obrigatorio!\n\n");
    }
    if ( (idade >=16) && (idade <18) || (idade >=65) ) {
         printf ("\n\t\tEleitor Facultativo!\n\n");
    }   
    getchar();
    getchar();
}
