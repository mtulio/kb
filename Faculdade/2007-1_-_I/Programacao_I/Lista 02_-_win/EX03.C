/*Exercicio 03 com algumas implementos como Informar o nome do aluno*/

#include <string.h>
#include <stdio.h>
main () {
     printf ("\n\t\t\tExercicio 03 - Lista 02\n\n");
     double numatr;
     float n1, n2, n3, mp, cd;
     char nome[20], sobren[15];
     printf ("Digite o nome do Aluno: ");
     scanf ("%s", &nome);
     printf ("DIgite o sobrenome do Aluno: ");
     scanf ("%s", &sobren);
     strcat (nome," ");
     strcat (nome,sobren);
     printf ("Digite o numero de Matricula do Aluno: ");
     scanf ("%lf", &numatr);
     printf ("Digite a 1º nota: ");
     scanf ("%f", &n1);
     printf ("Digite a 2º nota: ");
     scanf ("%f", &n2);
     printf ("Digite a 3º nota: ");
     scanf ("%f", &n3);
     if ( n1>n2 && n1>n3 ) {
          mp = (n1*4.0 + n2*3.0 + n3*3.0)/(4.0 + 3.0 + 3.0);
     }
     else {
          if ( n2>n3 ){
               mp = (n2*4.0 + n1*3.0 + n3*3.0)/(4.0 + 3.0 + 3.0);
          }
          else mp = (n3*4.0 + n1*3.0 + n2*3.0)/(4.0 + 3.0 + 3.0);
     }
     if ( mp>6.0 ) {
          printf ("\n\nNome do aluno: %s\nNumero de Matricula: %.0lf\nNota 1 = %.2f\nNota 2 = %.2f\nNota 3 = %.2f\nAPROVADO com a Media Ponderada de %.2f.\n\n",nome,numatr,n1,n2,n3,mp);
     }
     else printf ("\n\nNome do aluno: %s\nNumero de Matricula: %.0lf\nNota 1 = %.2f\nNota 2 = %.2f\nNota 3 = %.2f\nREPROVADO com a Media Ponderada de %.2f.\n\n",nome,numatr,n1,n2,n3,mp);
     
     
     fflush(stdin); //limpa buffet do teclado - Windows
     //__fpurge(stdin); //limpa buffet do teclado - Linux
     getchar();

}
