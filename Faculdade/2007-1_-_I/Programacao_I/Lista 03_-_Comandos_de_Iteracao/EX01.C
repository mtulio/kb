#include <stdio.h>
main () {
     int sidade=0, idade, i;
     float idmedia;
     
     for (i=1; idade !=0; i++) {
        printf ("Digite a %ia idade: ",i);
        scanf ("%i", &idade);
        sidade = idade + sidade;
        //printf ("idade = %i\nsidade = %i\ni = %i\n",idade,sidade,i); //> para confereir o exercicio
     }
     
     i = i-2;
     idmedia = sidade / i;
     //printf ("\n\nsidade = %i\ni = %i\n",sidade, i); //> para conferir o exercicio
     
     printf ("\nA idade media de %i individuos eh %.2f anos",i ,idmedia);
     getchar();
     getchar();
}    
