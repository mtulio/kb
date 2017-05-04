#include <stdio.h>
main () {
     int celcius;
     float fah;
     printf ("\nCalculo da Variaçao de 50 150 graus C em Fahrenheit.\n\n\tTecle enter para iniciar...Aguardando!\n");
     getchar();
     printf ("\t| Celcius | Fahrenheit |");
     for ( celcius=50; celcius<=150; celcius+=1) {
         fah = (9.0 * celcius + 160.0) / 5.0;
         if (celcius <=99) printf ("\n\t|__%i____|>|__%.2f___|\n",celcius, fah);
         if (celcius >=100) printf ("\n\t|__%i___|>|__%.2f___|\n",celcius, fah);        
         //printf ("\n\t|  %i   ||   %.2f   |\n",celcius, fah);
//         printf ("\n\t%i Graus Celcius = %.2f Graus Fahrenheit\n",celcius, fah);
     }
     //printf ("\t| Celcius | Fahrenheit |\n\t|  %i   ||   %.2f   |\n",celcius, fah);
     printf ("\n\n\tTecle Enter para Sair...\n");
     getchar();
     
}


