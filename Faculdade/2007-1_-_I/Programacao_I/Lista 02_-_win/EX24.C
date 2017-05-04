                        /*Marco Tulio*/

#include <stdio.h>
#include <string.h>
main () {
     printf ("\n\t\t\tExercicio 24 - Lista 02\n\n");
     char nome[10], sobrenome[15];
     int idade;
     printf ("\nDigite o Nome do Nadador: ");
     gets(nome);
     printf ("Digite o sobrenome do Nadador: ");
     gets(sobrenome);
     strcat(nome," ");
     strcat(nome,sobrenome);
     printf ("Digite a Idade do Nadador: ");
     scanf ("%i", &idade);
     if ( (idade >=5) && (idade <=7) ){
          printf ("\n\nNome: %s \nIdade: %.0i\nCategoria: Infantil A\n\n",nome, idade);
     }
     if ( (idade >=8) && (idade <=10) ){
          printf ("\n\nNome: %s \nIdade: %.0i\nCategoria: Infantil B\n\n",nome, idade);
     }
     if ( (idade >=11) && (idade <=13) ){
          printf ("\n\nNome: %s \nIdade: %.0i\nCategoria: Juvenil A\n\n",nome, idade);
     }
      if ( (idade >=14) && (idade <=17) ){
          printf ("\n\nNome: %s \nIdade: %.0i\nCategoria: Juvenil B\n\n",nome, idade);
     }
       if ( idade >=18 ){
          printf ("\n\nNome: %s \nIdade: %.0i\nCategoria: Sênior\n\n",nome, idade);
     }
     getchar();
     getchar();
}  
