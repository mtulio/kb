                    /*Marco Tulio*/
                    
#include <stdio.h>
int main (void) {
    printf ("\n\t\t\tExercicio 31 - Lista 02\n\n");
    int idade;
    printf ("Digite a idade para verificação Eleitoral: ");
    scanf ("%i", &idade);
    if (idade <16) {
         printf ("\n\t\tNão Eleitor!\n\n");
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
