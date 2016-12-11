#include <stdio.h>
int main (void) {
    int ano;

    printf ("\n\t\t\tExercicio 33 - Lista 02\n\n");
    printf ("Digite o ano para verificacao: ");
    scanf ("%i", &ano);

         if(ano%4==0){ //condicao a cada 4 anos - tempo do ano bissexto
           if (ano%100==0 & ano%400!=0)
               printf ("\nO ano %i nao e' Bissexto!\n",ano);
               else if (ano%100==0 & ano%400==0)
                  printf ("\nO ano %i e' bissexto!\n",ano);
                  else printf ("\n\nO ano %i e' bissexto!\n",ano);
         }
         else printf ("\nO ano %i nao e' Bissexto!\n",ano);

   fflush(stdin);      //-Rwindows
  //__fpurge(stdin); //-linux
   getchar();
}
