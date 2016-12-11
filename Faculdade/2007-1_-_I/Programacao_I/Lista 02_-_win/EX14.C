                    /*Marco Tulio*/
//Verificar, quando informado uma data, ex: 052007, imprimi o valor errado

#include <stdio.h>
main () {
     printf ("\n\t\t\tExercicio 14 - Lista 02\n\n");
     int dias,ma, mes, ano;
     printf ("\nDigite o mês e o ano da data desejada, ex.(mmaaaa): ");
     scanf ("%i", &ma);
//Com 1 mês = 30 dias, 1 ano = 365 dias.      
     
     mes = ma/10000;
     ano = ((ma%100000)%10000);
     
     printf ("\nMes = %.0i\nAno = %.0i",mes, ano);     
//     dias = (((ma/100000)*10)*30 + ((ma%100000)/10000)*30) + ((ma%100000)%10000)*365;
//     printf ("\nA quantidade de dias da data informada é %.0i dias.\n\n",dias);
     
     
     fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux
     getchar();
}
