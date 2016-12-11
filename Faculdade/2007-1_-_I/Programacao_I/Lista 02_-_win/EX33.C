                     /*Marco Tulio*/

#include <stdio.h>
int main (void) {
    int ano;
    printf ("\n\t\t\tExercicio 33 - Lista 02\n\n");
    printf ("Digite o ano para verificacao: ");
    scanf ("%i", &ano);

         if(ano%4==0){ //condicao a cada 4 anos - tempo do ano bissexto
           if (ano%100==0 & ano%400!=0) 
               printf ("\n\tO ano %i nao e' Bissexto!\n",ano);
               else if (ano%100==0 & ano%400==0)  //2º condição exigida no exercicio
                  printf ("\n\tO ano %i e' bissexto!\n",ano);
                  else printf ("\n\tO ano %i e' bissexto!\n",ano); //1º condição exigida no exercicio
         }
         else printf ("\n\tO ano %i nao e' Bissexto!\n",ano);

    getchar();
}

