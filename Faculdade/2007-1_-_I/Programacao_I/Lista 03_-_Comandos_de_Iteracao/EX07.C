#include "stdio.h"
#include<string.h>
main () {
     int ausente=0, A=1, mat, p, taus; 
     float qtd, pausentes;
     char T;
     for (T='A'; T<='N'; T++){
         printf ("\nDigite a quantidade de alunos para a turma %c :", T);
         scanf ("%f", &qtd);
         while (A<=qtd) {
               printf ("Digite o numero de matricula: ");
               scanf ("%i", &mat);
               do{
                     printf ("(1)-Presente\n(2)-Ausente:");
                     scanf ("%i", &p);
               }while (p<1 || p>2);
               if (p==2) ausente++;
               A++;
         }
         pausentes = (ausente/qtd)*100.0;
         printf ("\nA Turma %c tem %.2f Porcento de ausentes\n",T,pausentes);
         if (pausentes > 5.0) taus++;
     }
     printf ("Existem %i turmas com ausêmcia superior à 5%\n",taus);
}
