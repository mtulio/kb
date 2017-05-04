                     /*Marco Tulio*/
                     
#include <stdio.h>
main (void) {
     int sexo;
     float altura,pideal;
     printf ("\n\t\t\tExercicio 33 - Lista 02\n\n");
     printf ("\n\t(1)-Masculino\n\t(2)-Feminino\nInforme o Sexo: ");
     scanf ("%i", &sexo);
     printf ("Digite a altura, em metros: ");
     scanf ("%f", &altura);
     switch (sexo) {
            case 1:
                 pideal = (72.7*altura) - 58.0;
                 break;
            case 2:
                 pideal = (62.1*altura) - 44.7;
                 break;
            default:
                    printf ("\nOpção Invalida!\n");
     }
     printf ("\nO peso ideal e´ de %.2fKg",pideal);
     
     fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux
     getchar();
}
